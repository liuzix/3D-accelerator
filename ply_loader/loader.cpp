#include "happly.h"
#include "loader.h"
#include <tgmath.h>
#include <fstream>

typedef uint32_t fixed_point_t;
#define FIXED_POINT_FRACTIONAL_BITS 16
using namespace std;

/* calculate normal vector for each triangle */
Vec3 calcFaceNormal(Vec3 vpos[3], Vec3 vnormal[3]) {
	Vec3 p0 = vpos[1] - vpos[0];
	Vec3 p1 = vpos[2] - vpos[0];
	Vec3 faceNormal = p0.crossProduct(p1);

	Vec3 vertexNormal = vnormal[0];
	double dot = faceNormal.dotProduct(vertexNormal);
    faceNormal.normalize();

	return (dot < 0) ? -faceNormal : faceNormal;
}

/* double to fixed point conversion */
inline fixed_point_t float2fixed(double input)
{
    return (fixed_point_t)(round(input * (1 << FIXED_POINT_FRACTIONAL_BITS)));
}

int main(int argc, char** argv) {
	// Construct the data object by reading from file
	happly::PLYData plyIn("simple.ply");

	// Get mesh-style data from the object
	std::vector<std::array<double, 3>> vPos = plyIn.getVertexPositions();
	std::vector<std::array<unsigned char, 3>> vColor = plyIn.getVertexColors();
	std::vector<std::vector<size_t>> fInd = plyIn.getFaceIndices<size_t>();
	std::vector<double> vNx = plyIn.getElement("vertex").getProperty<double>("nx");
	std::vector<double> vNy = plyIn.getElement("vertex").getProperty<double>("ny");
	std::vector<double> vNz = plyIn.getElement("vertex").getProperty<double>("nz");

	std::vector<std::array<double, 3>> fNormal(fInd.size(), {0,0,0});


	std::cout << vPos.size() << " vectex in total" << std::endl;
	std::cout << fInd.size() << " triangles in total" << std::endl;

	for (int i = 0; i < fInd.size(); i++) {
		Vec3 vpos[3];
		Vec3 vnormal[3];

		vpos[0].load(vPos[fInd[i][0]]);
		vpos[1].load(vPos[fInd[i][1]]);
		vpos[2].load(vPos[fInd[i][2]]);

		vnormal[0].load({vNx[fInd[i][0]], vNy[fInd[i][0]], vNz[fInd[i][0]]});
		vnormal[1].load({vNx[fInd[i][1]], vNy[fInd[i][1]], vNz[fInd[i][1]]});
		vnormal[2].load({vNx[fInd[i][2]], vNy[fInd[i][2]], vNz[fInd[i][2]]});
		// calculate normal vector
		Vec3 faceNormal = calcFaceNormal(vpos, vnormal);

		fNormal[i] = {faceNormal.X, faceNormal.Y, faceNormal.Z};
	}

	// fixed point test
	uint64_t u;
	memcpy(&u, &vPos[0][2], sizeof(vPos[0][2]));
	std::cout << "before conversion: " << vPos[0][2] << " " << std::hex << u << std::endl;

	std::cout << "after conversion: " << std::bitset<32>(float2fixed(vPos[0][2])) << std::endl;
    cout << hex << float2fixed(vPos[0][2]) << endl;


	/* data_out: X|Y|Z--X|Y|Z--X|Y|Z--NX|NY|NZ
	 * color_out: R|G|B--R|G|B--R|G|B
	 * index for each triangle
	 */
	std::vector<std::vector<fixed_point_t>> data_out;
	std::vector<std::vector<unsigned char>> color_out;

	for (int i = 0; i < fInd.size(); i++) {

		/* get data for each triangle*/
		std::vector<fixed_point_t> pos_tmp;
		std::vector<unsigned char> col_tmp;
		for (int j = 0; j < 3; j++) {

			/* X Y Z */
			size_t index = fInd[i][j];
			pos_tmp.emplace_back(float2fixed(vPos[index][0]));
			pos_tmp.emplace_back(float2fixed(vPos[index][1]));
			pos_tmp.emplace_back(float2fixed(vPos[index][2]));
            if (argc > 1)
            std::cout << "( " << std::dec << vPos[index][0]
                << " " << vPos[index][1]
                << " " << vPos[index][2] << " )"  << std::endl;

			/* R G B */
			col_tmp.emplace_back(vColor[index][0]);
			col_tmp.emplace_back(vColor[index][1]);
			col_tmp.emplace_back(vColor[index][2]);

            if (argc > 1)
            std::cout << "RGB( " << std::dec << (unsigned int)vColor[index][0]
                << " " << (unsigned int)vColor[index][1]
                << " " << (unsigned int)vColor[index][2] << " )"  << std::endl;
		}

		/* NX NY NZ */
		pos_tmp.emplace_back(float2fixed(fNormal[i][0]));
		pos_tmp.emplace_back(float2fixed(fNormal[i][1]));
		pos_tmp.emplace_back(float2fixed(fNormal[i][2]));
        if (argc > 1) {
        std::cout << "NORMAL( " << std::dec << fNormal[i][0]
            << " " << fNormal[i][1]
            << " " << fNormal[i][2] << " )"  << std::endl;
        std::cout << std::endl;
        }

		data_out.emplace_back(pos_tmp);
		color_out.emplace_back(col_tmp);
	}

	std::cout << std::dec << data_out.size() << " triangles loaded in total" << std::endl;

	std::ofstream file_out("data.binary", std::ios_base::out | std::ios_base::binary);

	int tri = data_out.size();
	file_out.write((char*)&tri, sizeof(int));

	/* output file layout:
	 * X|Y|Z|R|G|B--X|Y|Z|R|G|B--X|Y|Z|R|G|B--NX|NY|NZ for each triangle
	 */
	for (int i = 0; i < data_out.size(); i++) {
		for (int j = 0; j < 3; j++) {
			file_out.write((char*)&data_out[i][0 + 3*j], sizeof(fixed_point_t));
			file_out.write((char*)&data_out[i][1 + 3*j], sizeof(fixed_point_t));
			file_out.write((char*)&data_out[i][2 + 3*j], sizeof(fixed_point_t));

			file_out << color_out[i][0 + 3*j];
			file_out << color_out[i][1 + 3*j];
			file_out << color_out[i][2 + 3*j];
            file_out << '\0';
		}

		file_out.write((char*)&data_out[i][9], sizeof(fixed_point_t));
		file_out.write((char*)&data_out[i][10], sizeof(fixed_point_t));
		file_out.write((char*)&data_out[i][11], sizeof(fixed_point_t));
	}
	file_out.close();

	std::cout << "output file generated" << std::endl;

	std::ifstream file_in("data.binary", std::ios_base::in | std::ios_base::binary);

	fixed_point_t buffer[9];
	file_in.read((char*)buffer, 9 * sizeof(fixed_point_t));

	for (int i = 3; i < 6; i++)
		std::cout << std::bitset<32>(data_out[0][i]) << " ";
	for (int i = 3; i < 6; i++)
        std::cout << std::bitset<8>(color_out[0][i]);

	std::cout << std::endl;
    std::cout << "|||||SHOULD BE THE SAME|||||" << std::endl;
	for (int i = 5; i < 9; i++)
		std::cout << std::bitset<32>(buffer[i]) << " ";
    cout << endl;
    

	file_in.close();

	return 0;

}
