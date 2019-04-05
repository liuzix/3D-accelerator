	component system is
		port (
			clk_clk                       : in    std_logic                     := 'X';             -- clk
			reset_reset_n                 : in    std_logic                     := 'X';             -- reset_n
			hps_ddr3_mem_a                : out   std_logic_vector(14 downto 0);                    -- mem_a
			hps_ddr3_mem_ba               : out   std_logic_vector(2 downto 0);                     -- mem_ba
			hps_ddr3_mem_ck               : out   std_logic;                                        -- mem_ck
			hps_ddr3_mem_ck_n             : out   std_logic;                                        -- mem_ck_n
			hps_ddr3_mem_cke              : out   std_logic;                                        -- mem_cke
			hps_ddr3_mem_cs_n             : out   std_logic;                                        -- mem_cs_n
			hps_ddr3_mem_ras_n            : out   std_logic;                                        -- mem_ras_n
			hps_ddr3_mem_cas_n            : out   std_logic;                                        -- mem_cas_n
			hps_ddr3_mem_we_n             : out   std_logic;                                        -- mem_we_n
			hps_ddr3_mem_reset_n          : out   std_logic;                                        -- mem_reset_n
			hps_ddr3_mem_dq               : inout std_logic_vector(31 downto 0) := (others => 'X'); -- mem_dq
			hps_ddr3_mem_dqs              : inout std_logic_vector(3 downto 0)  := (others => 'X'); -- mem_dqs
			hps_ddr3_mem_dqs_n            : inout std_logic_vector(3 downto 0)  := (others => 'X'); -- mem_dqs_n
			hps_ddr3_mem_odt              : out   std_logic;                                        -- mem_odt
			hps_ddr3_mem_dm               : out   std_logic_vector(3 downto 0);                     -- mem_dm
			hps_ddr3_oct_rzqin            : in    std_logic                     := 'X';             -- oct_rzqin
			hps_io_hps_io_sdio_inst_CMD   : inout std_logic                     := 'X';             -- hps_io_sdio_inst_CMD
			hps_io_hps_io_sdio_inst_D0    : inout std_logic                     := 'X';             -- hps_io_sdio_inst_D0
			hps_io_hps_io_sdio_inst_D1    : inout std_logic                     := 'X';             -- hps_io_sdio_inst_D1
			hps_io_hps_io_sdio_inst_CLK   : out   std_logic;                                        -- hps_io_sdio_inst_CLK
			hps_io_hps_io_sdio_inst_D2    : inout std_logic                     := 'X';             -- hps_io_sdio_inst_D2
			hps_io_hps_io_sdio_inst_D3    : inout std_logic                     := 'X';             -- hps_io_sdio_inst_D3
			hps_io_hps_io_usb1_inst_D0    : inout std_logic                     := 'X';             -- hps_io_usb1_inst_D0
			hps_io_hps_io_usb1_inst_D1    : inout std_logic                     := 'X';             -- hps_io_usb1_inst_D1
			hps_io_hps_io_usb1_inst_D2    : inout std_logic                     := 'X';             -- hps_io_usb1_inst_D2
			hps_io_hps_io_usb1_inst_D3    : inout std_logic                     := 'X';             -- hps_io_usb1_inst_D3
			hps_io_hps_io_usb1_inst_D4    : inout std_logic                     := 'X';             -- hps_io_usb1_inst_D4
			hps_io_hps_io_usb1_inst_D5    : inout std_logic                     := 'X';             -- hps_io_usb1_inst_D5
			hps_io_hps_io_usb1_inst_D6    : inout std_logic                     := 'X';             -- hps_io_usb1_inst_D6
			hps_io_hps_io_usb1_inst_D7    : inout std_logic                     := 'X';             -- hps_io_usb1_inst_D7
			hps_io_hps_io_usb1_inst_CLK   : in    std_logic                     := 'X';             -- hps_io_usb1_inst_CLK
			hps_io_hps_io_usb1_inst_STP   : out   std_logic;                                        -- hps_io_usb1_inst_STP
			hps_io_hps_io_usb1_inst_DIR   : in    std_logic                     := 'X';             -- hps_io_usb1_inst_DIR
			hps_io_hps_io_usb1_inst_NXT   : in    std_logic                     := 'X';             -- hps_io_usb1_inst_NXT
			hps_io_hps_io_spim1_inst_CLK  : out   std_logic;                                        -- hps_io_spim1_inst_CLK
			hps_io_hps_io_spim1_inst_MOSI : out   std_logic;                                        -- hps_io_spim1_inst_MOSI
			hps_io_hps_io_spim1_inst_MISO : in    std_logic                     := 'X';             -- hps_io_spim1_inst_MISO
			hps_io_hps_io_spim1_inst_SS0  : out   std_logic;                                        -- hps_io_spim1_inst_SS0
			hps_io_hps_io_uart0_inst_RX   : in    std_logic                     := 'X';             -- hps_io_uart0_inst_RX
			hps_io_hps_io_uart0_inst_TX   : out   std_logic;                                        -- hps_io_uart0_inst_TX
			hps_io_hps_io_i2c0_inst_SDA   : inout std_logic                     := 'X';             -- hps_io_i2c0_inst_SDA
			hps_io_hps_io_i2c0_inst_SCL   : inout std_logic                     := 'X';             -- hps_io_i2c0_inst_SCL
			hps_io_hps_io_i2c1_inst_SDA   : inout std_logic                     := 'X';             -- hps_io_i2c1_inst_SDA
			hps_io_hps_io_i2c1_inst_SCL   : inout std_logic                     := 'X';             -- hps_io_i2c1_inst_SCL
			sdram_addr                    : out   std_logic_vector(12 downto 0);                    -- addr
			sdram_ba                      : out   std_logic_vector(1 downto 0);                     -- ba
			sdram_cas_n                   : out   std_logic;                                        -- cas_n
			sdram_cke                     : out   std_logic;                                        -- cke
			sdram_cs_n                    : out   std_logic;                                        -- cs_n
			sdram_dq                      : inout std_logic_vector(15 downto 0) := (others => 'X'); -- dq
			sdram_dqm                     : out   std_logic_vector(1 downto 0);                     -- dqm
			sdram_ras_n                   : out   std_logic;                                        -- ras_n
			sdram_we_n                    : out   std_logic                                         -- we_n
		);
	end component system;

	u0 : component system
		port map (
			clk_clk                       => CONNECTED_TO_clk_clk,                       --      clk.clk
			reset_reset_n                 => CONNECTED_TO_reset_reset_n,                 --    reset.reset_n
			hps_ddr3_mem_a                => CONNECTED_TO_hps_ddr3_mem_a,                -- hps_ddr3.mem_a
			hps_ddr3_mem_ba               => CONNECTED_TO_hps_ddr3_mem_ba,               --         .mem_ba
			hps_ddr3_mem_ck               => CONNECTED_TO_hps_ddr3_mem_ck,               --         .mem_ck
			hps_ddr3_mem_ck_n             => CONNECTED_TO_hps_ddr3_mem_ck_n,             --         .mem_ck_n
			hps_ddr3_mem_cke              => CONNECTED_TO_hps_ddr3_mem_cke,              --         .mem_cke
			hps_ddr3_mem_cs_n             => CONNECTED_TO_hps_ddr3_mem_cs_n,             --         .mem_cs_n
			hps_ddr3_mem_ras_n            => CONNECTED_TO_hps_ddr3_mem_ras_n,            --         .mem_ras_n
			hps_ddr3_mem_cas_n            => CONNECTED_TO_hps_ddr3_mem_cas_n,            --         .mem_cas_n
			hps_ddr3_mem_we_n             => CONNECTED_TO_hps_ddr3_mem_we_n,             --         .mem_we_n
			hps_ddr3_mem_reset_n          => CONNECTED_TO_hps_ddr3_mem_reset_n,          --         .mem_reset_n
			hps_ddr3_mem_dq               => CONNECTED_TO_hps_ddr3_mem_dq,               --         .mem_dq
			hps_ddr3_mem_dqs              => CONNECTED_TO_hps_ddr3_mem_dqs,              --         .mem_dqs
			hps_ddr3_mem_dqs_n            => CONNECTED_TO_hps_ddr3_mem_dqs_n,            --         .mem_dqs_n
			hps_ddr3_mem_odt              => CONNECTED_TO_hps_ddr3_mem_odt,              --         .mem_odt
			hps_ddr3_mem_dm               => CONNECTED_TO_hps_ddr3_mem_dm,               --         .mem_dm
			hps_ddr3_oct_rzqin            => CONNECTED_TO_hps_ddr3_oct_rzqin,            --         .oct_rzqin
			hps_io_hps_io_sdio_inst_CMD   => CONNECTED_TO_hps_io_hps_io_sdio_inst_CMD,   --   hps_io.hps_io_sdio_inst_CMD
			hps_io_hps_io_sdio_inst_D0    => CONNECTED_TO_hps_io_hps_io_sdio_inst_D0,    --         .hps_io_sdio_inst_D0
			hps_io_hps_io_sdio_inst_D1    => CONNECTED_TO_hps_io_hps_io_sdio_inst_D1,    --         .hps_io_sdio_inst_D1
			hps_io_hps_io_sdio_inst_CLK   => CONNECTED_TO_hps_io_hps_io_sdio_inst_CLK,   --         .hps_io_sdio_inst_CLK
			hps_io_hps_io_sdio_inst_D2    => CONNECTED_TO_hps_io_hps_io_sdio_inst_D2,    --         .hps_io_sdio_inst_D2
			hps_io_hps_io_sdio_inst_D3    => CONNECTED_TO_hps_io_hps_io_sdio_inst_D3,    --         .hps_io_sdio_inst_D3
			hps_io_hps_io_usb1_inst_D0    => CONNECTED_TO_hps_io_hps_io_usb1_inst_D0,    --         .hps_io_usb1_inst_D0
			hps_io_hps_io_usb1_inst_D1    => CONNECTED_TO_hps_io_hps_io_usb1_inst_D1,    --         .hps_io_usb1_inst_D1
			hps_io_hps_io_usb1_inst_D2    => CONNECTED_TO_hps_io_hps_io_usb1_inst_D2,    --         .hps_io_usb1_inst_D2
			hps_io_hps_io_usb1_inst_D3    => CONNECTED_TO_hps_io_hps_io_usb1_inst_D3,    --         .hps_io_usb1_inst_D3
			hps_io_hps_io_usb1_inst_D4    => CONNECTED_TO_hps_io_hps_io_usb1_inst_D4,    --         .hps_io_usb1_inst_D4
			hps_io_hps_io_usb1_inst_D5    => CONNECTED_TO_hps_io_hps_io_usb1_inst_D5,    --         .hps_io_usb1_inst_D5
			hps_io_hps_io_usb1_inst_D6    => CONNECTED_TO_hps_io_hps_io_usb1_inst_D6,    --         .hps_io_usb1_inst_D6
			hps_io_hps_io_usb1_inst_D7    => CONNECTED_TO_hps_io_hps_io_usb1_inst_D7,    --         .hps_io_usb1_inst_D7
			hps_io_hps_io_usb1_inst_CLK   => CONNECTED_TO_hps_io_hps_io_usb1_inst_CLK,   --         .hps_io_usb1_inst_CLK
			hps_io_hps_io_usb1_inst_STP   => CONNECTED_TO_hps_io_hps_io_usb1_inst_STP,   --         .hps_io_usb1_inst_STP
			hps_io_hps_io_usb1_inst_DIR   => CONNECTED_TO_hps_io_hps_io_usb1_inst_DIR,   --         .hps_io_usb1_inst_DIR
			hps_io_hps_io_usb1_inst_NXT   => CONNECTED_TO_hps_io_hps_io_usb1_inst_NXT,   --         .hps_io_usb1_inst_NXT
			hps_io_hps_io_spim1_inst_CLK  => CONNECTED_TO_hps_io_hps_io_spim1_inst_CLK,  --         .hps_io_spim1_inst_CLK
			hps_io_hps_io_spim1_inst_MOSI => CONNECTED_TO_hps_io_hps_io_spim1_inst_MOSI, --         .hps_io_spim1_inst_MOSI
			hps_io_hps_io_spim1_inst_MISO => CONNECTED_TO_hps_io_hps_io_spim1_inst_MISO, --         .hps_io_spim1_inst_MISO
			hps_io_hps_io_spim1_inst_SS0  => CONNECTED_TO_hps_io_hps_io_spim1_inst_SS0,  --         .hps_io_spim1_inst_SS0
			hps_io_hps_io_uart0_inst_RX   => CONNECTED_TO_hps_io_hps_io_uart0_inst_RX,   --         .hps_io_uart0_inst_RX
			hps_io_hps_io_uart0_inst_TX   => CONNECTED_TO_hps_io_hps_io_uart0_inst_TX,   --         .hps_io_uart0_inst_TX
			hps_io_hps_io_i2c0_inst_SDA   => CONNECTED_TO_hps_io_hps_io_i2c0_inst_SDA,   --         .hps_io_i2c0_inst_SDA
			hps_io_hps_io_i2c0_inst_SCL   => CONNECTED_TO_hps_io_hps_io_i2c0_inst_SCL,   --         .hps_io_i2c0_inst_SCL
			hps_io_hps_io_i2c1_inst_SDA   => CONNECTED_TO_hps_io_hps_io_i2c1_inst_SDA,   --         .hps_io_i2c1_inst_SDA
			hps_io_hps_io_i2c1_inst_SCL   => CONNECTED_TO_hps_io_hps_io_i2c1_inst_SCL,   --         .hps_io_i2c1_inst_SCL
			sdram_addr                    => CONNECTED_TO_sdram_addr,                    --    sdram.addr
			sdram_ba                      => CONNECTED_TO_sdram_ba,                      --         .ba
			sdram_cas_n                   => CONNECTED_TO_sdram_cas_n,                   --         .cas_n
			sdram_cke                     => CONNECTED_TO_sdram_cke,                     --         .cke
			sdram_cs_n                    => CONNECTED_TO_sdram_cs_n,                    --         .cs_n
			sdram_dq                      => CONNECTED_TO_sdram_dq,                      --         .dq
			sdram_dqm                     => CONNECTED_TO_sdram_dqm,                     --         .dqm
			sdram_ras_n                   => CONNECTED_TO_sdram_ras_n,                   --         .ras_n
			sdram_we_n                    => CONNECTED_TO_sdram_we_n                     --         .we_n
		);

