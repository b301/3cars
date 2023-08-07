$cpp_files=Get-ChildItem -Path "src\impl" -Filter "*.cpp" -Recurse

# mkdir obj directory if it doesn't exist
if (!(Test-Path "obj")) {
    mkdir "obj"
}

# print the cpp files
echo "[Building]"
foreach ($cpp_file in $cpp_files) {
    # get the file name without the extension
    $file_name = $cpp_file.Name
    $file_name = $file_name.Substring(0, $file_name.Length - 4)

    # build the object file
    echo "$file_name.o"
    g++ -c "src\impl\$file_name.cpp" -Isrc\abst -Iinclude -o "obj\$file_name.o"
}

# link the object files under obj/ into executable file and include sfml
echo "[Linking]"
g++ obj/*.o -o 3cars.exe -Llib -lsfml-graphics -lsfml-window -lsfml-system

echo "Build complete! Run 3cars.exe to play the game."