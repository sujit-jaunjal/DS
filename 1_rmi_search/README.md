# RMI String Search

Steps to run RMI program:

- Open new terminal

```bash
cd 1_rmi_search
```

- Run

```bash
javac *.java
```

- Start registry

```bash
rmiregistry
```

- Open another teminal window

```bash
cd 1_rmi_search
```

- Create the Stubs using rmic

```bash
rmic SearchQuery
```

- Start the server

```bash
java SearchServer
```

- Open another teminal window

```bash
cd 1_rmi_search
```

- Run the client

```bash
java ClientRequest
```

```bash
⚠️ Make sure java jdk version is 1.8.x using java -version
```
