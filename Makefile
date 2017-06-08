CC=gcc 
CFLAGS=-c -Wall -Wextra
LDFLAGS= 
SOURCES=serial.c neoeka.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=xcalibus
UPX=/sur/bin/upx

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@
	strip $(EXECUTABLE)
	upx $(EXECUTABLE)
	hexdump -ve '1/1 "%.2X"' $(EXECUTABLE) | sed "s/546869732066696C65206973207061636B6564207769746820746865205550582065786563757461626C65207061636B657220687474703A2F2F7570782E73662E6E6574/2020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020202020/g" | sed "s/332E393120436F707972696768742028432920313939362D323031332074686520555058205465616D/2020202020202020202020202020202020202020202020202020202020202020202020202020202020/g" | sed "s/555058/202020/g" | xxd -r -p > file.patched
	mv file.patched $(EXECUTABLE)
	chmod +x $(EXECUTABLE)
	 
.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *.o