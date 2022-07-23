filename = input("Enter filename: ")
filename2 = input("Enter destination filename: ")

f = open(filename,"r");
f2 = open(filename2,"w")
line = f.readlines()
line2 = []
length = len(line)
data_set = int(length/500);
index  = 0
ini = 8
final = 500+ini-1

for j in range(0,data_set):
	print(ini,final) 
	for i in range(ini,final+1):
		line2.append(line[i])
		
	ini =  8+502*(j+1)
	final = ini+500-1
	
	
for i in range(0,len(line2)):
	print(line2[i],end="")
	f2.write(line2[i])
