import math
def rtd(Mat):
    t=Mat[0]
    r=Mat[1]
    x=r*(math.cos(math.radians(t)))
    y=r*(math.sin(math.radians(t)))
    mat=[]
    if t>=0 and t<=360:
        mat.append(x)
        mat.append(y)
    else:
        mat.append(0)
        mat.append(0)
    return mat
