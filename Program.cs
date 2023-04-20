using System.Net;
using System.Net.Sockets;
using System.Text;

var tcpListener = new TcpListener(IPAddress.Parse("127.0.0.1"), 8888);
 
try
{
    tcpListener.Start();    // запускаем сервер
    Console.WriteLine("Сервер запущен. Ожидание подключений... ");
 
    var data = new byte[65535];
    
    while (true)
    {
        // получаем подключение в виде Socket
        using var tcpSocket = await tcpListener.AcceptSocketAsync();
        Console.WriteLine($"Входящее подключение: {tcpSocket.RemoteEndPoint}");

        var result = tcpSocket.ReceiveFromAsync(data, SocketFlags.None, tcpSocket.RemoteEndPoint);
        var message = Encoding.UTF8.GetString(data, 0, result.Result.ReceivedBytes);
        Console.WriteLine(message);

    }
}
finally
{
    tcpListener.Stop();
}