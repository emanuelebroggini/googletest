# Utilizza un'immagine di base contenente il compilatore C++ e le dipendenze necessarie
 FROM gcc:latest
 
# Expose port :8080
# EXPOSE 8080

# Copia i file del progetto nella directory di lavoro dell'immagine
 COPY main/main.exe ./main/docker
# Imposta la directory di lavoro
 WORKDIR ./main/docker

# Installa eventuali dipendenze necessarie per il tuo progetto
 RUN apt-get update 
#   && apt-get install -y nome_dipendenza 

# Compila il codice sorgente
# RUN 

# Specifica l'eseguibile predefinito da avviare quando il container viene eseguito
 CMD ["./main.exe"] 
