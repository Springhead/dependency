#
CC = cl

$(ODIR)\$(FILE).obj: $(SDIR)\$(FILE).cpp $(HDRS)
	$(CC) $(COPT) $(SDIR)\$(FILE).cpp

