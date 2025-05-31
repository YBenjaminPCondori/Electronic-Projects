library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity Main is
    Port (
        clk : in STD_LOGIC;
        reset : in STD_LOGIC;
        BTND, BTNU, BTNL, BTNR, BTNC : in STD_LOGIC; -- Button inputs
        led : out STD_LOGIC;                         -- LED output
        btn_out_D, btn_out_U, btn_out_L, btn_out_R, btn_out_C : out STD_LOGIC -- Debounced outputs
    );
end Main;

architecture Behavioral of Main is

    -- Declare debouncing signals
    signal clk_div : STD_LOGIC;
    signal debounced_D, debounced_U, debounced_L, debounced_R, debounced_C : STD_LOGIC;

    -- Declare the state machine signals
    type State_Type is (S0, S1, S2, S3, S4, S5, S6, S7, q);
    signal current_state, next_state : State_Type;
    signal counter : INTEGER := 0;  -- Counter signal

    -- Components for debouncing
    component clock_divider is
        Port ( clk_in : in STD_LOGIC;
               clk_out : out STD_LOGIC );
    end component;

    component Debouncer is
        Port ( clk_in : in STD_LOGIC;
               btn_in : in STD_LOGIC;
               btn_out : out STD_LOGIC );
    end component;

begin

    -- Clock divider instantiation
    clk_div_inst : clock_divider
        port map (
            clk_in  => clk,
            clk_out => clk_div
        );

    -- Debouncer instances
    debouncer_D : Debouncer
        port map (
            clk_in  => clk_div,
            btn_in  => BTND,
            btn_out => debounced_D
        );

    debouncer_U : Debouncer
        port map (
            clk_in  => clk_div,
            btn_in  => BTNU,
            btn_out => debounced_U
        );

    debouncer_L : Debouncer
        port map (
            clk_in  => clk_div,
            btn_in  => BTNL,
            btn_out => debounced_L
        );

    debouncer_R : Debouncer
        port map (
            clk_in  => clk_div,
            btn_in  => BTNR,
            btn_out => debounced_R
        );

    debouncer_C : Debouncer
        port map (
            clk_in  => clk_div,
            btn_in  => BTNC,
            btn_out => debounced_C
        );

    -- Map debounced signals to outputs
    btn_out_D <= debounced_D;
    btn_out_U <= debounced_U;
    btn_out_L <= debounced_L;
    btn_out_R <= debounced_R;
    btn_out_C <= debounced_C;

    -- State machine logic
    process(clk, reset)
    begin
        if reset = '1' then
            current_state <= S0;
            counter <= 0;  -- Reset counter on reset
        elsif rising_edge(clk) then
            current_state <= next_state;  -- Update state on clock rising edge
        end if;
    end process;

    -- State machine transition logic
    process(current_state, debounced_L, debounced_U, debounced_R, debounced_D, debounced_C, counter)
    begin
        next_state <= current_state; -- Default state (no change)
        led <= '0'; -- Default LED state (off)

        case current_state is
            when S0 =>
                if counter < 10 then
                    if debounced_L = '1' then
                        next_state <= S1;
                        counter <= counter + 1;
                        led <= '1';  -- Turn LED on
                    elsif debounced_U = '1' then
                        next_state <= S6;
                        counter <= counter + 1;
                        led <= '1';  -- Turn LED on
                    end if;
                end if;

            when S1 =>
                if counter < 10 then
                    if debounced_U = '1' then
                        next_state <= S2;
                        counter <= counter + 1;
                        led <= '1';  -- Turn LED on
                    end if;
                end if;

            when S2 =>
                if counter < 10 then
                    if debounced_U = '1' then
                        next_state <= S3;
                        counter <= counter + 1;
                        led <= '1';  -- Turn LED on
                    elsif debounced_L = '1' then
                        next_state <= q;  -- Transition to q state
                        counter <= counter + 1;
                        led <= '1';  -- Turn LED on
                    end if;
                end if;

            when S3 =>
                if counter < 10 then
                    if debounced_R = '1' then
                        next_state <= S4;
                        counter <= counter + 1;
                        led <= '1';  -- Turn LED on
                    end if;
                end if;

            when S4 =>
                if counter < 10 then
                    if debounced_D = '1' then
                        next_state <= S5;
                        counter <= counter + 1;
                        led <= '1';  -- Turn LED on
                    end if;
                end if;

            when S5 =>
                if counter < 10 then
                    if debounced_C = '1' then
                        next_state <= S0;
                        counter <= 0;  -- Reset counter
                        led <= '1';  -- Turn LED on
                    end if;
                end if;

            when S6 =>
                if counter = 10 then
                    if debounced_U = '1' then
                        next_state <= S7;
                        counter <= counter + 1;
                        led <= '1';  -- Turn LED on
                    end if;
                end if;

            when S7 =>
                if counter <= 10 then
                    if debounced_C = '1' then
                        next_state <= S0;
                        counter <= 0;  -- Reset counter
                        led <= '1';  -- Turn LED on
                    end if;
                end if;

            when others =>
                next_state <= S0;  -- Default to state S0
        end case;
    end process;

end Behavioral;
