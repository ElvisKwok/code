chan request = [2] of {byte, chan};
chan reply = [5] of {byte};

active [2] proctype Sever() {
    byte client;
    chan replyChannel;
    do
    ::  request ? client, replyChannel ->
        printf("Client %d processed by server %d\n", client, _pid);
        replyChannel ! _pid 
    od
}

active [5] proctype Client() {
    byte serverID;
    do
    ::  request ! _pid, reply ->
            reply ? serverID;
        printf("client %d is requesting server %d\n", _pid, serverID)
    od
}
