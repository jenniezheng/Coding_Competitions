#Example: make script="a.py"
default:
	make run;
	make watch --silent;

watch:
	while true; do \
		make run ; \
		#wait for changes to script
		inotifywait -qre modify $(script) >> /dev/null; \
    done

run:
	#if running c++, then gcc compile and then run
	python3 $(script);

push:
	git add *
	echo -n "Message: "
	read msg; \
	echo "git commit -am" $$msg; \
	git commit -am "$$msg";
	git push origin master
