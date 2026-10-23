derive_pll_clocks
derive_clock_uncertainty

# core specific constraints

# The CPU clock (PLL output 1, 8 MHz) is in phase with the system clock
# (output 0, 64 MHz); the paths between them are timed as related clocks.
