#run like make script="a.py"
default:
	make run;
	make watch --silent;

watch:
	while true; do \
		make run ; \
		inotifywait -qre close_write . >> /dev/null; \
    done

run:
	python3 $(script);

update:
	git add *
	echo -n "Message: "
	read msg; \
	echo "git commit -am" $$msg; \
	git commit -am "$$msg";
	git push origin master
