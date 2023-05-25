# Corba String Reverse

Steps to run RMI program:

- Open new terminal

```bash
cd 2_corba_string
```

- Convert the .idl file to java stubs

```bash
idlj -fall ReverseModule.idl
```

- Run

```bash
javac **/*.java
```

- Start the orbd server

```bash
orbd -ORBInitialPort 1050
```

- Open another teminal window

```bash
cd 2_corba_string
```

- Run the Server

```bash
java ReverseServer -ORBInitialPort 1050 -ORBInitialHost localhost
```

- Open another teminal window

```bash
cd 2_corba_string
```

- Start the client

```bash
java ReverseClient -ORBInitialPort 1050 -ORBInitialHost localhost
```

```bash
⚠️ Make sure java jdk version is 1.8.x using java -version
```
