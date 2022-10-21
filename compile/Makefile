SRCDIR = ../src
INCDIR = ../include
BINDIR = ../bin
OBJDIR = ../obj
CFLAGS = gcc -c -g -I${INCDIR}

all:	main.o addCustomer.o updateCustomer.o deleteCustomer.o manageCustomer.o addRequest.o updateRequest.o  deleteRequest.o manageRequest.o reports.o demo.o complaint.o service.o generateID.o findCustomer.o
main.o:
	${CFLAGS} ${SRCDIR}/main.c -o ${OBJDIR}/main.o
crmLogin.o:
	${CFLAGS} ${SRCDIR}/crmLogin.c -o ${OBJDIR}/crmLogin.o
customerLogin.o:
	${CFLAGS} ${SRCDIR}/customerLogin.c -o ${OBJDIR}/customerLogin.o	
addCustomer.o:
	${CFLAGS} ${SRCDIR}/addCustomer.c -o ${OBJDIR}/addCustomer.o
updateCustomer.o:	
	${CFLAGS} ${SRCDIR}/updateCustomer.c -o ${OBJDIR}/updateCustomer.o
deleteCustomer.o:	
	${CFLAGS} ${SRCDIR}/deleteCustomer.c -o ${OBJDIR}/deleteCustomer.o	
manageCustomer.o:
	${CFLAGS} ${SRCDIR}/manageCustomer.c -o ${OBJDIR}/manageCustomer.o
addRequest.o:	
	${CFLAGS} ${SRCDIR}/addRequest.c -o ${OBJDIR}/addRequest.o	
updateRequest.o:	
	${CFLAGS} ${SRCDIR}/updateRequest.c -o ${OBJDIR}/updateRequest.o
deleteRequest.o:	
	${CFLAGS} ${SRCDIR}/deleteRequest.c -o ${OBJDIR}/deleteRequest.o
manageRequest.o:
	${CFLAGS} ${SRCDIR}/manageRequest.c -o ${OBJDIR}/manageRequest.o
reports.o:
	${CFLAGS} ${SRCDIR}/reports.c -o ${OBJDIR}/reports.o
demo.o:
	${CFLAGS} ${SRCDIR}/demo.c -o ${OBJDIR}/demo.o
complaint.o:
	${CFLAGS} ${SRCDIR}/complaint.c -o ${OBJDIR}/complaint.o
service.o:
	${CFLAGS} ${SRCDIR}/service.c -o ${OBJDIR}/service.o
generateID.o:
	${CFLAGS} ${SRCDIR}/generateID.c -o ${OBJDIR}/generateID.o
findCustomer.o:
	${CFLAGS} ${SRCDIR}/findCustomer.c -o ${OBJDIR}/findCustomer.o	

finalexe: 
	gcc ${OBJDIR}/main.o ${OBJDIR}/addCustomer.o ${OBJDIR}/updateCustomer.o ${OBJDIR}/deleteCustomer.o ${OBJDIR}/manageCustomer.o ${OBJDIR}/addRequest.o ${OBJDIR}/updateRequest.o ${OBJDIR}/deleteRequest.o ${OBJDIR}/manageRequest.o ${OBJDIR}/reports.o ${OBJDIR}/demo.o ${OBJDIR}/complaint.o ${OBJDIR}/service.o ${OBJDIR}/generateID.o ${OBJDIR}/findCustomer.o -o ${BINDIR}/main.exe
clean:
	rm ${OBJDIR}/main.o ${OBJDIR}/addCustomer.o ${OBJDIR}/updateCustomer.o ${OBJDIR}/deleteCustomer.o ${OBJDIR}/manageCustomer.o ${OBJDIR}/addRequest.o ${OBJDIR}/updateRequest.o ${OBJDIR}/deleteRequest.o ${OBJDIR}/manageRequest.o ${OBJDIR}/reports.o ${OBJDIR}/demo.o ${OBJDIR}/complaint.o ${OBJDIR}/service.o ${OBJDIR}/generateID.o ${OBJDIR}/findCustomer.o

