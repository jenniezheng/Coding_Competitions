if [ "$#" -ne 1 ]; then
    echo "Usage: make SCRIPT"
    exit 1
fi

script=$1
while true; do
    python3 $script < test.txt
    #wait for changes to script
    inotifywait -qe modify $script >> /dev/null;
done