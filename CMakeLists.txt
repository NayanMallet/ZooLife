cmake_minimum_required(VERSION 3.24)
project(ZooLife)

set(CMAKE_CXX_STANDARD 11)

add_executable(ZooLife main.cpp Animaux/IAnimal.cpp Animaux/IAnimal.h Aliments/Aliment.cpp Aliments/Aliment.h Animaux/Tigre.h Animaux/Aigle.h Animaux/Poule.cpp Animaux/Aigle.cpp Animaux/Tigre.cpp Aliments/Viande.cpp Aliments/Viande.h Aliments/Graines.cpp Aliments/Graines.h Functions/functions.cpp Functions/functions.h Habitats/Habitat.cpp Animaux/Coq.cpp Animaux/Coq.h Animaux/Coq.h Zoo/Zoo.h Zoo/Zoo.cpp Vendeur/Vendeur.cpp Vendeur/Vendeur.h Budget/Budget.cpp Budget/Budget.h)
