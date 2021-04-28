using System;
using System.Net;
using Newtonsoft.Json;
using System.IO;
using System.Net;
using System.Text;

namespace Scrapper
{
    public class Controller
    {
        public static String getUrlBody(String url = "https://prograd.ufabc.edu.br/calendarios") 
        {
            WebRequest request = WebRequest.Create(url);
            request.Credentials = CredentialCache.DefaultCredentials;
            HttpWebResponse response = (HttpWebResponse) request.GetResponse();
            Console.WriteLine (response.StatusDescription);
            String responseFromServer = "";
            if (response.StatusDescription.ToUpper() == "OK")
            {
            Stream dataStream = response.GetResponseStream();
            StreamReader reader = new StreamReader(dataStream);
            responseFromServer = reader.ReadToEnd ();
            reader.Close ();
            dataStream.Close ();
            }
            //Console.WriteLine (responseFromServer);
            response.Close ();

            return responseFromServer;
        }
    }
}
