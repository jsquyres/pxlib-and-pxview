
%.1: %.sgml
	$(DOC_TO_MAN) $< > $@

%.html: %.sgml
	docbook2html $<
	mv index.html $@

distclean: clean
	rm -f Makefile

clean:
	rm -f ${man_MANS} ${man_HTMLS}

SGML_FILES = pxview.sgml px2csv.sgml px2html.sgml px2sql.sgml px2sqlite.sgml

EXTRA_DIST = $(SGML_FILES)

man_MANS = $(SGML_FILES:.sgml=.1)
man_HTMLS = $(SGML_FILES:.sgml=.html)

html: $(SGML_FILES:.sgml=.html)
