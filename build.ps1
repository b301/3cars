g++ -c src/impl/main.cpp -Isrc/abst -Iinclude -o obj/main.o
g++ -c src/impl/game.cpp -Isrc/abst -Iinclude -o obj/game.o
g++ -c src/impl/car.cpp -Isrc/abst -Iinclude -o obj/car.o 
g++ -c src/impl/obstacle.cpp -Isrc/abst -Iinclude -o obj/obstacle.o 
g++ -c src/impl/cars_handler.cpp -Isrc/abst -Iinclude -o obj/cars_handler.o

# link the object files under obj/ into executable file and include sfml
g++ obj/main.o obj/game.o obj/car.o obj/obstacle.o obj/cars_handler.o `
    -o 3cars.exe -Iinclude -Llib -lsfml-graphics -lsfml-window -lsfml-system