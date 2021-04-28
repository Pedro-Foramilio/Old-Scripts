using System;
using System.Net;
using Newtonsoft.Json;
using System.IO;
using System.Net;
using System.Text;

namespace Scrapper
{
    class Program
    {
        static void Main(string[] args)
        {
            Controller controller = new Controller();
            String body = Controller.getUrlBody();
            Console.WriteLine(body);
        }
    }
}
