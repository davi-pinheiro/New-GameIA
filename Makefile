GPP = g++
INCLUDE = -Ibuild
FLAGS = -Wall -pedantic -g -ansi -Iinclude -Iinclude/effects -Iinclude/entities/collectibles -Iinclude/entities/npcs -Iinclude/entities/relationship -Iinclude/world
PROGRAMA = main

OBJ = build/vivo.o build/main.o build/vampiro.o build/janela.o build/rgba.o build/tempo.o build/personagem.o build/guerreiro.o build/camera.o build/coletavel.o build/denteAlho.o build/backMap.o build/area.o build/subArea.o build/relationship.o build/worlds.o build/caveWorld.o build/normalWorld.o

bin/$(PROGRAMA): $(OBJ)
	g++ -o $@ $^ `sdl2-config --cflags --libs`



build/coletavel.o: src/entities/collectibles/coletavel.cpp
	$(GPP) $(FLAGS) -c -o $@ $^
build/denteAlho.o: src/entities/collectibles/denteAlho.cpp
	$(GPP) $(FLAGS) -c -o $@ $^



build/vivo.o: src/entities/npcs/vivo.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/vampiro.o: src/entities/npcs/vampiro.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/guerreiro.o: src/entities/npcs/guerreiro.cpp
	$(GPP) $(FLAGS) -c -o $@ $^



build/relationship.o: src/entities/relationship/relationship.cpp
	$(GPP) $(FLAGS) -c -o $@ $^



build/backMap.o: src/world/backMap.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/normalWorld.o: src/world/normalWorld.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/caveWorld.o: src/world/caveWorld.cpp
	$(GPP) $(FLAGS) -c -o $@ $^



build/main.o: src/main.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/janela.o: src/janela.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/rgba.o: src/rgba.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/tempo.o: src/tempo.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/personagem.o: src/personagem.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/camera.o: src/camera.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/area.o: src/area.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/subArea.o: src/subArea.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/worlds.o: src/worlds.cpp
	$(GPP) $(FLAGS) -c -o $@ $^



clean_obj:
	rm build/*.o

clean_bin:
	rm bin/$(PROGRAMA)

clean_all:
	rm build/*.o
	rm bin/$(PROGRAMA)
