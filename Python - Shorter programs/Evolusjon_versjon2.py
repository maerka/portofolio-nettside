# -*- coding: utf-8 -*-
"""
Created on Sun Nov  6 18:40:14 2022

@author: Erlend
"""

import random as r
import matplotlib.pyplot as plt
import numpy as np


class Fugl:
    #Definer fuglens egenskaper. Nummer er nummeret i kolonien
    def __init__(self, farge, fart, nummer):
        
        self.nummer=nummer
        self.farge= farge
        self.fart = fart
        self.alder =0
        self.levende=1
    
    #Print ut fuglens egenskaper
    def __str__(self):
        return(f'Fugl {self.nummer} \nFarge: {self.farge} \nFart:  {self.fart}')


    
#Funksjonen skaper n fugler med definerte egenskaper. Forbedring: Bør normalfordeles rundt en spesifikk farge. Ta inn fargen som argument
def skapFugler(n):
    fugleKoloni = []
    for i in range(n):
        #Setter en tilfeldig farge mellom 0 og 255. 
        # farge = r.randint(0, 25)
        farge = round(r.normalvariate(50, 5))
        #Setter en tilfeldig fart mellom 40 og 70
        fart = r.randint(40, 70)
        #Samler alle fuglene i en liste som returneres.
        fugleKoloni.append(Fugl(farge, fart, i+1))
    return fugleKoloni

#Samler alle fargene til alle dyrene i en liste
def fugleFarger(alleDyr):  
    alleFarger =[]
    for i in range(len(alleDyr)):
        alleFarger.append(alleDyr[i].farge)
    return alleFarger
    

# Tar inn en liste med dyr og printer alle dyrenes egenskaper (printfunksjon må være definert i klassen)
def visKoloni(alleDyr):
    for i in alleDyr:
        print(i)
        
#Viser et histogram av en gitt liste. 
def visHistogram(liste):  
    bins4 = range(20, 90, 5)
    plt.hist(liste, bins = bins4 , edgecolor="grey")
    plt.xlabel('Farge')
    plt.ylabel('Antall')
    plt.title('Antall fugler med gitt farge')

# def lagAvkom(fugl):
    

# ****** TEST OF PROGRAM ******
listeMedFugler = skapFugler(10)   
farger = fugleFarger(listeMedFugler)
 
bakgrunnsfarge = 60

# visHistogram(farger)
visHistogram(fugleFarger(listeMedFugler))

dodeFugler =[]
print(len(listeMedFugler))

for aar in range(10):
    it=0
    print(f'År {aar} starter med {len(listeMedFugler)} fugler')
    for fugl in listeMedFugler:
        sjanse = r.randint(0, 100)
        if fugl.farge > bakgrunnsfarge-5 and fugl.farge < bakgrunnsfarge+5:
            if sjanse >5:
                fugl.alder+=1
                listeMedFugler.append(fugl)
            else:
                fugl.levende=0
                listeMedFugler.pop(it)
                dodeFugler.append(fugl)
        elif fugl.farge > bakgrunnsfarge-20 and fugl.farge < bakgrunnsfarge+20:
            if sjanse >20:
                fugl.alder+=1
                listeMedFugler.append(fugl)
            else:
                fugl.levende=0
                listeMedFugler.pop(it)
                dodeFugler.append(fugl)
        else:
            if sjanse >80:
                fugl.alder+=1
                listeMedFugler.append(fugl)
            else:
                fugl.levende=0
                listeMedFugler.pop(it)
                dodeFugler.append(fugl)
        #print(it)
        it+=1


visHistogram(fugleFarger(listeMedFugler))         
print('Nå er det', len(listeMedFugler), 'fugler')    
                
            
        