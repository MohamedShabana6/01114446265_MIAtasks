

# main class to acces health and energy
class Villian():
    
    def __init__(self,name,health,energy):
        self.name = name
        self.health = health
        self.energy = energy

    #calulation od the damage dealt With the Sheild Used against it
    def dealdamage(self,damageOfOneSide,oppositeSavePercentage):
        
            
        reduction = oppositeSavePercentage / 100
        damageOfOneSide *= (1 - reduction)
        self.health -= damageOfOneSide

    
class Weapon(Villian):
    def __init__(self,name,energy,damage):
        self.name = name
        self.energy = energy
        self.damage = damage

class Shield(Villian):
    def __init__(self,name,energy,save_percentage):
        self.name = name
        self.energy = energy
        self.save_percentage = save_percentage

class GruWeapon(Weapon):
    Damage = 0
    #counters to caclultate the resources used 
    electricProd = 0
    megaMagnet = 0
    kalmanMissle = 0
    def __init__(self,name,energy,damage,resources):
        super().__init__(name,energy,damage)
        self.resources = resources

class GruShield(Shield):
    Save_percentage = 0
    #counters to caclultate the resources used 
    selectivePermeability = 0
    def __init__(self,name,energy,save_percentage,resources):
        super().__init__(name,energy,save_percentage)
        self.resources = resources

class VectorWeapon(Weapon):
    Damage = 0
    #counters to caclultate the resources used 
    plasmaGrenades = 0
    soincResonanceCanon= 0
    def __init__(self,name,energy,damage,resources):
        super().__init__(name,energy,damage)
        self.resources = resources

class VectorShield(Shield):
    Save_percentage = 0
    #counters to caclultate the resources used 
    energyNetTrap = 0
    quantumDeflector = 0
    def __init__(self,name,energy,save_percentage,resources):
        super().__init__(name,energy,save_percentage)
        self.resources = resources


def Battle_Field(Gweapon,Gshield,Vweapon,Vshield):


    #create instances of the weapons for each villian
    #GRU WEAPONS
    if Gweapon.lower() == "freeze gun":
        freeze_gun = GruWeapon(Gweapon, 50, 11, -1)
        GruWeapon.Damage = freeze_gun.damage
        #GRUWeapon class has a static variable attribute "Damage" which takes the damage of the weapon object created before
        if Gru.energy>=freeze_gun.energy:
            Gru.energy-=freeze_gun.energy
        else:
            GruWeapon.Damage = 0
        
    elif Gweapon.lower() == "electric prod":
        electric_prod = GruWeapon(Gweapon, 88, 18, 5)
        
        GruWeapon.Damage = electric_prod.damage
        if(GruWeapon.electricProd < electric_prod.resources and Gru.energy>=electric_prod.energy):
            GruWeapon.electricProd +=1 
            Gru.energy-=electric_prod.energy
        else:
            GruWeapon.Damage = 0
            
    elif Gweapon.lower() == "mega magnet":
        mega_magnet = GruWeapon(Gweapon, 92, 10, 3)
        
        GruWeapon.Damage = mega_magnet.damage
        if(GruWeapon.megaMagnet < mega_magnet.resources and Gru.energy >= mega_magnet.energy):
            GruWeapon.megaMagnet +=1 
            Gru.energy-=mega_magnet.energy
        else:
            GruWeapon.Damage = 0
    elif Gweapon.lower() == "kalman missile":
        kalman_missile = GruWeapon(Gweapon, 120, 20, 1)
        
        GruWeapon.Damage = kalman_missile.damage
        if(GruWeapon.kalmanMissle < kalman_missile.resources and Gru.energy >= kalman_missile.energy):
            GruWeapon.kalmanMissle +=1 
            Gru.energy-=kalman_missile.energy
        else:
            GruWeapon.Damage = 0
    else :
        GruWeapon.Damage = 0
        

    #VECTOR WEAPONS
    if Vweapon.lower() == "laser blaster":
        laser_blasters = VectorWeapon(Vweapon, 40, 8, -1)
        VectorWeapon.Damage = laser_blasters.damage
         #VectorWeapon class has a static variable attribute "Damage" which takes the damage of the weapon object created before
        if Vector.energy>=laser_blasters.energy:
            Vector.energy-=laser_blasters.energy
        else:
            VectorWeapon.Damage = 0
        
    elif Vweapon.lower() == "plasma grenades":
        plasma_grenades = VectorWeapon(Vweapon, 56, 13, 8)
        VectorWeapon.Damage = plasma_grenades.damage
        
        if(VectorWeapon.plasmaGrenades < plasma_grenades.resources and Vector.energy >= plasma_grenades.energy):
            VectorWeapon.plasmaGrenades +=1 
            Vector.energy-=plasma_grenades.energy
        else:
            VectorWeapon.Damage = 0
    elif Vweapon.lower() == "sonic resonance cannon":
        sonic_resonance_cannon = VectorWeapon(Vweapon, 100, 22, 3)
        
        VectorWeapon.Damage = sonic_resonance_cannon.damage
        if(VectorWeapon.soincResonanceCanon < sonic_resonance_cannon.resources and Vector.energy >= sonic_resonance_cannon.energy):
            VectorWeapon.soincResonanceCanon +=1 
            Vector.energy-=sonic_resonance_cannon.energy
        else:
            VectorWeapon.Damage = 0
    else:

        VectorWeapon.Damage = 0


    #create instances of the Shields for each villian
    #GRU SHIELDS
    if Gshield.lower() == "energy projected barrier gun":
        energy_projected_barrier_gun = GruShield(Gshield, 20, 40, -1)
        GruShield.Save_percentage = energy_projected_barrier_gun.save_percentage
        #GruShield class has a static variable attribute "Save_percentage" which takes the save percentage of the shield object created before
        if Gru.energy>=energy_projected_barrier_gun.energy:
            Gru.energy-=energy_projected_barrier_gun.energy
        else:
            GruShield.Save_percentage = 0

    elif Gshield.lower() == "selective permeability":
        selective_permeability = GruShield(Gshield, 50, 90, 2)
        GruShield.Save_percentage = selective_permeability.save_percentage
        
        if(GruShield.selectivePermeability < selective_permeability.resources and Gru.energy>=selective_permeability.energy):
            GruShield.selectivePermeability +=1 
            Gru.energy-=selective_permeability.energy
        else:
            GruShield.Save_percentage = 0
    else:
        
        GruShield.Save_percentage = 0
        
    
    #VECTOR SHIELDS
    if Vshield.lower() == "energy net trap":
        energy_net_trap = VectorShield(Vshield, 15, 32, -1)
        VectorShield.Save_percentage = energy_net_trap.save_percentage
        #VectorShield class has a static variable attribute "Save_percentage" which takes the save percentage of the shield object created before
        if Vector.energy>=energy_net_trap.energy:
            Vector.energy-=energy_net_trap.energy
        else:
            VectorShield.Save_percentage = 0
        
    elif Vshield.lower() == "quantum deflector":
        quantum_deflector = VectorShield(Vshield, 40, 80, 3)
        VectorShield.Save_percentage = quantum_deflector.save_percentage
        
        if(VectorShield.quantumDeflector < quantum_deflector.resources and Vector.energy>= quantum_deflector.energy):
           Vector.energy-=quantum_deflector.energy
           VectorShield.quantumDeflector +=1 
        else:
            VectorShield.Save_percentage = 0
    else:
        
        VectorShield.Save_percentage = 0

        
    if Gweapon.lower() == "kalman missile":# special case when kalman missile is used (no shiled can reduce the damage)
        Vector.dealdamage(GruWeapon.Damage,VectorShield.Save_percentage * 0)
    else:
        Vector.dealdamage(GruWeapon.Damage,VectorShield.Save_percentage )

    if Gweapon.lower() == "mega magnet":#special case when mega magnet is used (reduce opponent attack by 20%)
        Gru.dealdamage(VectorWeapon.Damage * 0.8 ,GruShield.Save_percentage)
    else:
        Gru.dealdamage(VectorWeapon.Damage , GruShield.Save_percentage)
 




Gru = Villian("Gru",100,500)
Vector = Villian("Vector",100,500)
#loop until health of one villian is zero or less or Energy of both villians reach the critical value of each
while (Gru.health>0 and Vector.health>0) and (Gru.energy>20 or Vector.energy>15):

    GWeapon = input("Enter gru weapon: ")
    GShield = input("Enter gru Shield: ")
    VWeapon = input("Enter vector weapon: ")
    VShield = input("Enter vector Shield: ")
    
    Battle_Field(GWeapon,GShield,VWeapon,VShield)# function to start the battle
    print(f"Gru Health: {Gru.health}\t Gru Energy: {Gru.energy}\n")
    print(f"Vector Health: {Vector.health}\t Vector Energy: {Vector.energy}")

if(Gru.health <= 0):
    print("\nvector Winssssss!!!!\n")

elif(Vector.health <= 0):
    print("\nGru Winssssss!!!!\n")

elif(Gru.health>Vector.health):
    print("\nGru Winssssss!!!!\n")

elif(Gru.health<Vector.health):
    print("\nvector Winssssss!!!!\n")

elif(Gru.health == Vector.health):
    print("\nDraw\n")

