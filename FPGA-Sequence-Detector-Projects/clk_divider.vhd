library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity clock_divider is
    Generic (
        divider : integer := 50000000 -- Adjust for desired frequency (e.g., 1Hz for 50MHz input)
    );
    Port (
        clk_in   : in STD_LOGIC;  -- Input clock
        clk_out  : out STD_LOGIC -- Slower output clock
    );
end clock_divider;

architecture Behavioral of clock_divider is
    signal counter : integer range 0 to divider - 1 := 0;
    signal clk_reg : STD_LOGIC := '0';
begin
    process (clk_in)
    begin
        if rising_edge(clk_in) then
            if counter = divider - 1 then
                counter <= 0;
                clk_reg <= NOT clk_reg; -- Toggle clock
            else
                counter <= counter + 1;
            end if;
        end if;
    end process;

    clk_out <= clk_reg;
end Behavioral;
