all:
	pdflatex -shell-escape thesis.tex 
	bibtex thesis
	makeglossaries thesis
	pdflatex -shell-escape thesis.tex
	pdflatex -shell-escape thesis.tex
