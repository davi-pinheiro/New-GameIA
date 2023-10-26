GPP = g++
INCLUDE = -Ibuild
FLAGS = -Wall -pedantic -g -ansi -Iinclude
PROGRAMA = main

OBJ = build/vivo.o build/main.o build/vampiro.o build/janela.o build/rgba.o build/monsterCollection.o build/tempo.o build/personagem.o build/allyCollection.o build/guerreiro.o build/controle.o build/camera.o build/coletavel.o build/denteAlho.o build/collectibleCollection.o build/backMap.o build/area.o build/subArea.o

bin/$(PROGRAMA): $(OBJ)
	g++ -o $@ $^ `sdl2-config --cflags --libs`

build/vivo.o: src/vivo.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/main.o: src/main.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/vampiro.o: src/vampiro.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/janela.o: src/janela.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/rgba.o: src/rgba.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/monsterCollection.o: src/monsterCollection.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/tempo.o: src/tempo.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/personagem.o: src/personagem.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/allyCollection.o: src/allyCollection.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/guerreiro.o: src/guerreiro.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/controle.o: src/controle.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/camera.o: src/camera.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/coletavel.o: src/coletavel.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/denteAlho.o: src/denteAlho.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/collectibleCollection.o: src/collectibleCollection.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/backMap.o: src/backMap.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/area.o: src/area.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

build/subArea.o: src/subArea.cpp
	$(GPP) $(FLAGS) -c -o $@ $^

clean_obj:
	rm build/*.o

clean_bin:
	rm bin/$(PROGRAMA)

clean_all:
	rm build/*.o
	rm bin/$(PROGRAMA)
