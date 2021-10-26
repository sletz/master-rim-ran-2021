## Procédure pour compiler un plugin générique stéréo



**1)** télécharger le SDK : https://vcvrack.com/downloads/

**2)** ouvrir un terminal, se placer dans le dossier du SDK (Rack-SDK) avec « **cd  /path/to/SDK** » 

**3)** dans le terminal taper : **export RACK_DIR="/path/to/SDK"**

**4)** dans le terminal taper pour créer le plugin : **./helper.py createplugin MyPlugin**
	
**5)** un nouveau dossier MyPlugin est créé, se placer dans ce dossier avec « **cd MyPlugin** » 

**6)** télécharger le fichier MyModule.svg depuis cette URL https://github.com/sletz/master-rim-ran-2021/tree/master/vcvrack et le mettre dans le dossier MyPlugin/res 

**7)** créer le fichier C++ à partir de cette interface SVG, avec dans le terminal : 

**../helper.py createmodule MyModule res/MyModule.svg src/MyModule.cpp**

**8)** ouvrir les fichiers plugin.hpp et plugin.cpp et décommenter les 2 lignes nécessaires 

(To enable the module, add
extern Model *modelMyModule;
to plugin.hpp, and add
p->addModel(modelMyModule);
to the init() function in plugin.cpp.)

**9)** dans le terminal taper : **make**

**10)** dans le terminal taper : **make install**

**11)** ouvrir l’application VCV Rack et vérifier que le nouveau plugin apparait
