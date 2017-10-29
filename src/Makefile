output: gbsh.o MatrixCalculator.o ShellCommandManager.o ShellData.o ShellDataManager.o ShellView.o ShellViewController.o
	gcc gbsh.o MatrixCalculator.o ShellCommandManager.o ShellData.o ShellDataManager.o ShellView.o ShellViewController.o -o output

gbsh.o: gbsh.c
	gcc -c gbsh.c

MatrixCalculator.o: MatrixCalculator.c MatrixCalculator.h
	gcc -c MatrixCalculator.c

ShellCommandManager.o: ShellCommandManager.c ShellCommandManager.h
	gcc -c ShellCommandManager.c

ShellData.o: ShellData.c ShellData.h
	gcc -c ShellData.c

ShellDataManager.o: ShellDataManager.c ShellDataManager.h
	gcc -c ShellDataManager.c

ShellView.o: ShellView.c ShellView.h
	gcc -c ShellView.c

ShellViewController.o: ShellViewController.c ShellViewController.h
	gcc -c ShellViewController.c

clean:
	rm *.o
