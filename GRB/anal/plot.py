import os
dir_path = os.getcwd()
assert dir_path == "/home/galgoczi/cubesat/Thickness_Experiment/anal"

for filename in os.listdir("./"):
    if filename.endswith(".txt"):
        os.remove(filename)

print("Deleted all files")

for filename in os.listdir("../res/"):
    if filename.endswith(".res"): 
         # print(os.path.join(directory, filename))
        #print filename.split('.')
        with open("../res/"+filename) as f:
			first_line = f.readline()
			
			with open(filename.split('.')[1]+".txt", "a") as myfile:
				myfile.write(filename.split('.')[0]+" "+str(10000-int(first_line))+"\n")
			
        continue
    else:
        continue
