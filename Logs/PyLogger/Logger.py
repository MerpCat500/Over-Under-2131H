import serial.tools.list_ports
import json
import matplotlib.pyplot as plt
import matplotlib.animation as animation

# def Animate(Path):
    
#     graph_data = open(Path)
#     lines = graph_data.split("\n")

#     xs=[]
#     ys=[]
    
#     for line in lines:
#         if len(lines) > 0:
#             x, y = 0
            
#     ax1.clear()
#     ax1.plot()
    
# ax1 = fig.add_subplot(1,1,1)

# ani = animation.FuncAnimation(fig, Animate('Logs/Graph1.csv'), interval=100)
# plt.show()
                
if __name__ == "__main__":
    
    fig = plt.figure()
    # serialInst = serial.Serial('COM6', 115200) 
    FirstLine = True
    Graphs = []
    
    while True:
        # if serialInst.in_waiting:
        #     packet = serialInst.readline()
        #     packet = packet.decode("utf-8")
            
        if FirstLine:
            FirstLine = False
                
            Format = {
                "NAME":
                {
                    "XValCol":0,
                    "yValCol":(1,2,3)
                },
                "NAME2":
                {
                    "XValCol":0,
                    "yValCol":(2)
                }
            }
        
            for  index, x in enumerate(Format.keys()): 
                Graphs.append(fig.add_subplot(index+1, 1, index+1))
            
                fig.subplots
                
            
