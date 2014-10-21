chan ch = [0] of { byte, byte };

/* global to make visible in
   SpinSpider */
byte  hour, minute;

active proctype Sender() {
  printf("ready\n");
  ch ! 11, 45;
  printf("Sent\n")
}
 
active proctype Receiver() {
  printf("steady\n");
  ch ? hour, minute;
  printf("Received\n")
}
