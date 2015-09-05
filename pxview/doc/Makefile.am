.sgml.1:
	$(DOC_TO_MAN) $< > $@

.sgml.html:
	docbook2html $<
	mv index.html $@

SGML_FILES = pxview.sgml px2csv.sgml px2html.sgml px2sql.sgml px2sqlite.sgml

EXTRA_DIST = $(SGML_FILES)

if BUILD_DOCS
nodist_man_MANS = $(SGML_FILES:.sgml=.1)
nodist_man_HTMLS = $(SGML_FILES:.sgml=.html)
endif

html: $(SGML_FILES:.sgml=.html)
