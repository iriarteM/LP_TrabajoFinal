install.packages("agricolae")
library(agricolae)

# Carga de datos
dataOrig <- read.csv("C:/Users/miria/OneDrive/Documentos/Universidad de Lima/2023 - 1/Lenguajes de Programación/Trabajo de Investigación/LP/imgO.csv", header = TRUE)
dataModiC <- read.csv("C:/Users/miria/OneDrive/Documentos/Universidad de Lima/2023 - 1/Lenguajes de Programación/Trabajo de Investigación/LP/imgC.csv", header = TRUE)
dataModiB <- read.csv("C:/Users/miria/OneDrive/Documentos/Universidad de Lima/2023 - 1/Lenguajes de Programación/Trabajo de Investigación/LP/imgB.csv", header = TRUE)

# Generar vectores simples
hist_valuesO <- unlist(dataOrig)
hist_valuesMC <- unlist(dataModiC)
hist_valuesMB <- unlist(dataModiB)

# Histogramas
hO <- hist(hist_valuesO, main = "Histograma", xlab = "Valor", ylab = "Frecuencia", breaks = 45, col = "#7FB3D5")
polygon.freq(hO, frequency = 1, col = "darkred", lwd = 2)
hMC <- hist(hist_valuesMC, main = "Histograma", xlab = "Valor", ylab = "Frecuencia", breaks = 45, col = "#7FB3D5")
polygon.freq(hMC, frequency = 1, col = "darkred", lwd = 2)
hMB <- hist(hist_valuesMB, main = "Histograma", xlab = "Valor", ylab = "Frecuencia", breaks = 45, col = "#7FB3D5")
polygon.freq(hMB, frequency = 1, col = "darkred", lwd = 2)

