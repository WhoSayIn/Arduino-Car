#!/usr/bin/python
# -*- coding: utf-8 -*-

# Huseyin KELES
# http://whosayin.com
# 22.12.2013

import serial
import pygame

port = '/dev/ttyACM0'
baud = 9600
connection = serial.Serial(port, baud)

window = pygame.display.set_mode((100, 100))
clock = pygame.time.Clock()

keydown = {pygame.K_q : "1",
          pygame.K_w : "2",
          pygame.K_a : "3",
          pygame.K_s : "4"}

keyup  = {pygame.K_q : "5",
          pygame.K_w : "6",
          pygame.K_a : "5",
          pygame.K_s : "6"}

running = 1
while running:
    window.fill((00, 00, 00))

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            connection.close()
            running = False
        elif event.type == pygame.KEYDOWN:
            connection.write(keydown.get(event.key, ""))
            print keydown.get(event.key, "")
        elif event.type == pygame.KEYUP:
            connection.write(keyup.get(event.key, ""))
            print keyup.get(event.key, "")

    time = clock.tick(30)
