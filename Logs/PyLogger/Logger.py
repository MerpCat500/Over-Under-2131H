import pandas as pd
import serial.tools.list_ports
import matplotlib.pyplot as plt
import matplotlib.animation as animation


plt.rcParams["figure.figsize"] = [7.00, 3.50]
plt.rcParams["figure.autolayout"] = True

def SelectPort():
    Ports = serial.tools.list_ports.comports()

    portList = []

    for Port in Ports:
        portList.append(str(Port))
        print(str(Port))
        
    SCOM = "COM" + input("Select Port:\n COM")

    for x in range(0 , len(portList)):
        
        if portList[x].startswith(SCOM):
            print(f"Graphing Port: {portList[x]}")
            serialInst = serial.Serial(SCOM, 115200)    

def AnimateCVS(Path):
    
    graph_data = open(Path)
    lines = graph_data.split("\n")

    xs=[]
    ys=[]
    
    for line in lines:
        if len(lines) > 0:
            x, y = 0
            
    ax1.clear()
    ax1.plot(df)
    
                
if __name__ == "__main__":
    
    fig = plt.figure()
    ax1 = fig.add_subplot(1,1,1)
    
    ani = animation.FuncAnimation(fig, A('Logs/Graph1.csv'), interval=100)
    plt.show()
        
    # if serialInst.in_waiting:
    #     packet = serialInst.readline()
    #     packet = packet.decode("utf-8")
    
        
        # with open("myfile.txt", "w") as file1:
        #     # Writing data to a file
        #     file1.write("Hello \n")
        
        


