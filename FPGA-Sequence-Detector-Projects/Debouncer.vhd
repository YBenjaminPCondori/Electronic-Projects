library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Debouncer is
    Port (
        clk_in : in STD_LOGIC;         -- Clock signal
        btn_in : in STD_LOGIC;         -- Button input
        btn_out : out STD_LOGIC -- Debounced button output
    );
end Debouncer;

architecture Behavioral of Debouncer is
    constant delay : integer := 650000;  -- Adjust for desired debouncing time
    signal count : integer := 0;
    signal btn_tmp : STD_LOGIC := '0'; 
begin
    process (clk_in)
    begin
        if rising_edge(clk_in) then
            if btn_in /= btn_tmp then
                btn_tmp <= btn_in;
                count <= 0;
            elsif count = delay then
                btn_out <= btn_tmp;
            else
                count <= count + 1;
            end if;
        end if;
    end process;

end Behavioral;
