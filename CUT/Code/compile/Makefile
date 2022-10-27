SRCDIR = ../src
INCDIR = ../include
BINDIR = ../bin
OBJDIR = ../obj
CFLAGS = gcc -c -g -I${INCDIR}

all:	main.o validate.o crm_menu.o customer_menu.o customers.o requests.o reports.o requests_desc.o

main.o:
	${CFLAGS} ${SRCDIR}/main.c -o ${OBJDIR}/main.o
crm_menu.o:
	${CFLAGS} ${SRCDIR}/crm_menu.c -o ${OBJDIR}/crm_menu.o
customer_menu.o:
	${CFLAGS} ${SRCDIR}/customer_menu.c -o ${OBJDIR}/customer_menu.o	
validate.o:
	${CFLAGS} ${SRCDIR}/validate.c -o ${OBJDIR}/validate.o
customers.o:	
	${CFLAGS} ${SRCDIR}/customers.c -o ${OBJDIR}/customers.o
requests.o:	
	${CFLAGS} ${SRCDIR}/requests.c -o ${OBJDIR}/requests.o	
reports.o:
	${CFLAGS} ${SRCDIR}/reports.c -o ${OBJDIR}/reports.o
requests_desc.o:	
	${CFLAGS} ${SRCDIR}/requests_desc.c -o ${OBJDIR}/requests_desc.o

finalexe: 
	gcc ${OBJDIR}/main.o ${OBJDIR}/crm_menu.o ${OBJDIR}/customer_menu.o ${OBJDIR}/customers.o ${OBJDIR}/requests.o ${OBJDIR}/reports.o ${OBJDIR}/requests_desc.o ${OBJDIR}/validate.o -o ${BINDIR}/application.exe

clean:
	${OBJDIR}/main.o ${OBJDIR}/crm_menu.o ${OBJDIR}/customer_menu.o ${OBJDIR}/customers.o ${OBJDIR}/requests.o ${OBJDIR}/reports.o ${OBJDIR}/requests_desc.o ${OBJDIR}/validate.o