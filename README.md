# ROBOism-individual-project
Digital Signal analyzer using Arduino :: As we know that for making a good and advanced project you need a digital signal analyzer. Arduino can do this without any modifications but it will be very slow and since you are only limited to millis and delay, you need to dig deeper in ATmega 328p infrastructure. 


INSTRUCTION::
  1: choose a appropiate frequency
      by writing a OCRA value in Arduino and then upload it 
  2: Attach your Device on any on of the PIND pins
  3: open a Serial monitor and extract the data , trigger the source multiple times to obtain all the data point
  4: use the provided Python program to extract the useful data
  5: then by using a Excel file make the graph 


and there you have your data ....

frequency = 16000000/(1+OCRA)
