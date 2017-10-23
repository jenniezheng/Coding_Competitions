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
	utop $(script);

