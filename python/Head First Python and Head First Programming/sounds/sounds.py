import pygame.mixer
sounds = pygame.mixer
sounds.init()
def wait_finish(channel):
    while channel.get_busy():
        pass

s=sounds.sound("heartbeat.wav")
wait_finish(s.play())
s2=sounds.sound("buzz.wav")
wait_finish(s2.play())
s3=sounds.sound("ohno.wav")
wait_finish(s3.play())
s4=sounds.sound("carhorn.wav")
wait_finish(s4.play())
