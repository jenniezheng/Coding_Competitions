if [ "$#" -ne 1 ]; then
    echo "Usage: make SCRIPT"
    exit 1
fi

script=$1
while true; do
    g++ -std=c++0x $script
    ./a.out
    #python3 $1 < test.txt
    #wait for changes to script
    inotifywait -qe modify $script test.txt >> /dev/null;
done