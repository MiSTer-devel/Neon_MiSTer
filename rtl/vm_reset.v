//
// vm_reset.v
//
// DCLO/ACLO power-up sequence for the VM2: DCLO drops first, ACLO after
// it, as the start-up circuit of the machine does.  From tang-uknc's
// wmrst.v (MIT).
//
module vm_reset
(
   input  clk,
   input  reset,
   output dclo,
   output aclo
);

assign dclo = ~powerup[4];
assign aclo = ~(&powerup[4:3]);

reg [4:0] powerup = 0;
always @(posedge clk or posedge reset)
   if(reset) powerup <= 0;
   else powerup <= !aclo ? powerup : powerup + 1'b1;

endmodule
