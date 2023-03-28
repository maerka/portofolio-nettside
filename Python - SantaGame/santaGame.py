# -*- coding: utf-8 -*-
"""
Created on Sat Jan  7 19:23:36 2023

@author: Erlend
"""

# https://www.youtube.com/watch?v=AY9MnQ4x3zk
# https://docs.spyder-ide.org/5/faq.html#using-packages-installer

import pygame #installed in kernel 3.9.13 ('base': conda)
from sys import exit
from random import randint, choice

class Player(pygame.sprite.Sprite):
    def __init__(self):
        super().__init__()
        self.player_jump = pygame.image.load('graphics/reindeer_jump.png').convert_alpha()         
        player_walk1 = pygame.image.load('graphics/reindeer_walk1.png').convert_alpha()
        player_walk2 = pygame.image.load('graphics/reindeer_walk2.png').convert_alpha()
        self.player_walk = [player_walk1, player_walk2] #All images in "walking" animation
        self.player_index = 0
        self.image = self.player_walk[self.player_index] #The image the game class starts with
        self.rect = self.image.get_rect(midbottom = (770 ,310)) #Rectangle of image
        self.gravity = 0
        self.dead = 0 #1 if dead
        self.animation_count = 0 #Used for animation after collision
        
        self.jump_sound = pygame.mixer.Sound('sound/wee.mp3')
        self.dead_sound = pygame.mixer.Sound('sound/dead.mp3')
        # self.music_battle = pygame.mixer.Sound('sound/battle.mp3')
        # self.music_battle.play()
        

    def player_input(self):
        keys = pygame.key.get_pressed()
        if keys[pygame.K_SPACE] and self.rect.bottom >= 310: #Jump!
            self.gravity = -4
            self.jump_sound.play()
            

    
    def apply_gravity(self):
        if self.dead and self.animation_count <25:
            self.gravity += 1
            self.rect.top += self.gravity
        else:
            self.gravity +=0.1
            self.rect.top += self.gravity #Updates image while falling
            if self.rect.bottom >= 310: #Avoid falling through the floor
                self.rect.bottom = 310        

    
    def animation_state(self):
        #Animation after collision
        if self.dead and self.animation_count <25:
            rect_temp = self.rect.center #Get Rectangle center to rotate properly
            self.image = pygame.transform.rotozoom(self.image, -10, 1.03) #rotate and enlarge
            self.rect = self.image.get_rect(center = rect_temp) #update rectangle
            self.animation_count +=1 #rotate 25 times         
        else:
            #Alive and jumping
            if self.rect.bottom < 310:
                self.image = self.player_jump
                # print(self.image.get_rect)
            #Alive and walking                
            else:
                 self.player_index += 0.1
                 if self.player_index >= len(self.player_walk):
                     self.player_index = 0
                 self.image = self.player_walk[int(self.player_index)]
    
             
    def game_over(self):
        self.dead = 1
        if self.animation_count == 0: #Sets gravity the first time code is run
            self.jump_sound.stop()    
            self.dead_sound.play()
            # self.dead_sound.set_volume(0.5)
            self.gravity = -6
             
    
    def update(self):
        self.player_input() #Inputs from keyboard?
        self.apply_gravity() #move player according to gravityj
        self.animation_state()  #Updates image 
        

    

class Obstacle(pygame.sprite.Sprite):
    
    def __init__(self, type): #builds obstacles of type "grinch" or "santa"
        super().__init__()
        if type == 'grinch':
            grinch1 = pygame.image.load('graphics/grinch_sled6.png').convert_alpha()
            grinch2 = grinch1 
            self.frames = [grinch1, grinch2] #Add image for an animation
            y_pos = 220 #in air
            self.x_vel = 5
            
        else:
            santa1 = pygame.image.load(('graphics/santa2.png')).convert_alpha()
            santa2 = santa1
            self.frames = [santa1, santa2] #Add image for an animation
            y_pos = 310 #groud level
            self.x_vel = 4
        self.kill_sound = pygame.mixer.Sound('sound/hoho.mp3')
        self.animation_index = 0
        self.image = self.frames[self.animation_index]
        self.rect = self.image.get_rect(midbottom = (randint(-300,-100), y_pos)) #Spawn at -300 < x < -100


    def animation_state(self):
        self.animation_index += 0.1
        if self.animation_index >= len(self.frames):
            self.animation_index = 0
        self.image = self.frames[int(self.animation_index)]        

    def destroy(self):
        if self.rect.x >= 900:
            self.kill()

    def play_sound(self):
        # self.kill_sound.play()
        v=0 #does not do anything

    def update(self):
        self.animation_state()
        self.rect.x += self.x_vel
        self.destroy()
        
        

# Handles the score
def display_score(game_state, score):        
    if game_state == 1:
        score = pygame.time.get_ticks() - start_time #.get_ticks() runs at all time in background. Start_time is set to .get_tick() when starting new game
        # score = (5350)
    
    score_surf = font.render(f'{int(score/100)}', True, (64,64,64))
    score_rect = score_surf.get_rect(center = (700,50))
    screen.blit(score_surf,score_rect)
    return score  



def collision_sprite():
    collisions = pygame.sprite.spritecollide(player.sprite, obstacle_group, False )#(sprite, groupe, bool kill?)
    #returns a list of alle collisions. Empty if no collisions
    if collisions: 
        #if not empty -> collision --> return False --> game_state = 0
        collisions[0].play_sound()
        # print(collision_sprite())
        return 2
    else:
        #if empty -> no collision --> return True --> game_state = 1 --> keep on running the game
        return 1


# ------- *** ------- SETTING UP THE GAME ------- *** --------
    
# Game logics
pygame.init()
screen = pygame.display.set_mode((860,400))
pygame.display.set_caption('Rudolf')
clock = pygame.time.Clock()
game_state = 0 # 0= new game? 1= game running 2= animation for game over 
start_time = 0
score = 0
animation_count = 0
music_game = pygame.mixer.Sound('sound/grieg.mp3')
# music_menu = pygame.mixer.Sound('sound/battle.mp3')
music_menu = pygame.mixer.Sound('sound/flower.mp3')      
kill_sound = pygame.mixer.Sound('sound/hoho.mp3')
music_menu.play()


#Timer
obstacle_timer = pygame.USEREVENT + 1
pygame.time.set_timer(obstacle_timer, 2000) #an event that happens every 2 seconds
keys = pygame.key.get_pressed()
 



# Colors: https://matplotlib.org/2.0.2/examples/color/named_colors.html
background = pygame.image.load('graphics/bakgrunn.png').convert_alpha() #(860x343) 
ground_brown = pygame.Surface((860,70))
ground_brown.fill('sandybrown')
ground_green = pygame.Surface((860,20))
ground_green.fill('olivedrab')
# ground_green.fill('azure')




# Text on display
font = pygame.font.Font(None, 50) #font of text -> (font type, font size) font type can be imported from file
text_surface = font.render('God jul!',True,'red') #(text, antialiasing - smootening, color)
menu_start_text = font.render('Start game', True, 'Red')
menu_start = menu_start_text.get_rect(midbottom = (430, 180))
menu_quit_text = font.render('Quit', True, 'red')
menu_quit = menu_quit_text.get_rect(midbottom = (430, 230))


#Class in groups (Groups)


player = pygame.sprite.GroupSingle()
player.add(Player())

obstacle_group = pygame.sprite.Group()


# enumerate(game_state_collision = "game_state_collision")



# ------- *** ------- RUNNING THE GAME ------- *** --------
while True:
    
    # KEYS AND GAME LOGIC
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            exit()

        # Game_state = 1 (running)
        if game_state == 1:    
            if event.type == obstacle_timer:
                obstacle_group.add(Obstacle(choice(['santa','santa','santa', 'grinch'])))              
        
        # Game_state = 0 (menu)
        elif game_state == 0:
            # Start game from keyboard
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_SPACE:
                    game_state =1
                    start_time = pygame.time.get_ticks()
                    music_menu.stop()
                    music_game.play()                    
                elif event.key == pygame.K_ESCAPE:
                    pygame.quit()
                    exit()
            # Start game by clicking with mouse                    
            if event.type == pygame.MOUSEBUTTONDOWN:
                if menu_start.collidepoint(pygame.mouse.get_pos()): #if mouse position inside rectangle "start game" 
                    game_state = 1
                    music_menu.stop()
                    music_game.play()
                    start_time = pygame.time.get_ticks()
                elif menu_quit.collidepoint(pygame.mouse.get_pos()):
                    pygame.quit()
                    exit()     
        
    #UPDATE ANIMATION            
    #1= game is running 2= game over animation
    if game_state == 1 or game_state == 2:
        #Background and ground
        screen.blit(background,(0,0))
        screen.blit(ground_brown,(0,330))
        screen.blit(text_surface,(200,50))
        screen.blit(ground_green,(0,310))
        #Score
        score = display_score(game_state, score)
        #Player
        player.draw(screen)
        player.update()
        #Obstacle
        obstacle_group.draw(screen)       
        obstacle_group.update()
        
        # CHECK FOR COLLISIONS   
        game_state = collision_sprite()
        if game_state == 2: #start dead player animation
            player.sprite.game_over()
            
    
    else: #if game_state == 0: (menu) 
        screen.blit(background,(0,0))
        screen.blit(ground_brown,(0,330))
        screen.blit(menu_start_text, menu_start)
        screen.blit(menu_quit_text, menu_quit)
    
    # Animation after collision
    # if is_after_collision():
        
    if game_state == 2:
        if animation_count == 0:
            kill_sound.play()
        animation_count +=1
        
        # RESET THE GAME
        if animation_count == 50:
            
            obstacle_group.empty() #deletes all obstacles and player
            player.empty()  
            player = pygame.sprite.GroupSingle() #build new player
            player.add(Player())
            animation_count = 0
            game_state = 0
            music_game.stop()
            music_menu.play()
    
    pygame.display.update()
    clock.tick(60)
        


         