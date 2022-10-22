SRCDIR = ../src
INCDIR = ../include
BINDIR = ../bin
OBJDIR = ../obj
CFLAGS = gcc -c -g -I${INCDIR}

all:	main.o CRM_login.o customer_login.o 

main.o:
	${CFLAGS} ${SRCDIR}/main.c -o ${OBJDIR}/main.o
CRM_login.o:
	${CFLAGS} ${SRCDIR}/CRM_login.c -o ${OBJDIR}/CRM_login.o
customer_login.o:
	${CFLAGS} ${SRCDIR}/customer_login.c -o ${OBJDIR}/customer_login.o	
generate_ID.o:
	${CFLAGS} ${SRCDIR}/generate_ID.c -o ${OBJDIR}/generate_ID.o
customers.o:	
	${CFLAGS} ${SRCDIR}/customers.c -o ${OBJDIR}/customers.o
requests.o:	
	${CFLAGS} ${SRCDIR}/requests.c -o ${OBJDIR}/requests.o	
reports.o:
	${CFLAGS} ${SRCDIR}/reports.c -o ${OBJDIR}/reports.o
requests_desc.o:	
	${CFLAGS} ${SRCDIR}/requests_desc.c -o ${OBJDIR}/requests_desc.o



finalexe: 
	gcc ${OBJDIR}/main.o ${OBJDIR}/CRM_login.o ${OBJDIR}/customer_login.o -o ${BINDIR}/application.exe

clean:
	rm ${OBJDIR}/main.o ${OBJDIR}/generate_ID.o ${OBJDIR}/customers.o ${OBJDIR}/requests.o ${OBJDIR}/reports.o ${OBJDIR}/requests_desc.o 
