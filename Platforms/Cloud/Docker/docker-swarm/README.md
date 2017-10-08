# Learn Docker Swarm with Vagrant
### Create a cluster
```bash
docker swarm init --advertise-addr 192.168.50.2
# in docker node
docker swarm join --token <token> 192.168.50.2:<port>
```

### Service Manager
```bash
# List of running serices
docker service ls
# list of tasks services
docker service ps <service_name>
# Create a service
docker service create --name qqexpress -p 8080:8080 --mode global dhiefphams/express # global mode, run in all node
# Remove service
docker service rm <service_name>
docker service create --name qqexpress -p 8080:8080 --replicas 2 dhiefphams/express # replicas mode
# Scale service
docker service scale <service_name>=5
# Leave the swarm
docker swarm leave --force
# in manager node, the swarm will be destroy but in child node, service still running
```

### Node manager
```
# Show list of nodes
docker node ls
# Node that are runnings services
docker node ps
# Remove a node
docker node rm <id>
```