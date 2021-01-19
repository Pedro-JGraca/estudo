import matplotlib.pyplot as plt
from scipy import signal
from scipy.io import wavfile
import numpy as np

a = []
a.append('Brandenburg Concerto No. 3 In G Major- I-Allegro_RED.wav')
a.append('há gente aqui_RED.wav')
a.append('Two Part Invention In F Major_RED.wav')
a.append('When I am laid in earth (Dido_s lament)_RED.wav')
show = a[3]
sample_rate, samples = wavfile.read(show)
frequencies, times, spectrogram = signal.stft(samples, sample_rate,nperseg=1024)
plt.pcolormesh(times, frequencies, np.abs(spectrogram) , shading='gouraud', cmap='CMRmap')
plt.title(show)
plt.ylabel('Frequency [Hz]')
plt.xlabel('Time [sec]')
plt.show()


#signal_wave = wave.open('Brandenburg Concerto No. 3 In G Major- I-Allegro_RED.wav', 'r')
#sample_rate = 44100
#sig = np.frombuffer(signal_wave.readframes(sample_rate), dtype=np.int16)

#plt.figure(1)

#plot_a = plt.subplot(211)
#plot_a.plot(sig)
#plot_a.set_xlabel('sample rate * time')
#plot_a.set_ylabel('energy')


#plot_b = plt.subplot(212)
#plt.specgram()
#k=2
#plot_b.specgram(sig, NFFT=k*1024, Fs=sample_rate, noverlap=None)
#plot_b.set_xlabel('Time')
#plot_b.set_ylabel('Frequency')

#plt.show()