using System;
using System.Windows.Forms;

namespace Chat
{
    static class Program
    {
        [STAThread]
        static void Main()
        {
            var cc = Contact.Create();

            Contact c = new Contact();
            c.Name("Hello C#");
            var name = c.Name();

            c.RegisterOnNameChange((string str) => {
                int a = 0;
            });

            c.Callback2((Contact c2) => {
                var name1 = c.Name();
                var name2 = c2.Name();
                var id2 = c2.Id();
                int a = 0;
            });

            var s = new Session();
            s.AddContact(c);
            s.AddContact(c);
            s.AddContact(c);

            s.IntTest1(true, 2, 3, 4, 5, 6, 7);
            s.IntTest2(2, 3, 4, 5, 6, 7);
            var b = s.AutoTest();

            c.SendContacts(new Contact[]{ c, c });
            var aa2 = c.TestArray(new int[]{ 5, 6 });
            var aa3 = c.TestArray2(new float[] { 5.5F, 6.5F });

            //var contacts = s.Contacts();

            var m = new Model();
            var p1 = new Struct2();
            p1.strings = new string[] { "hello1", "hello2" };
            p1.callback = (string str) => {
                return str + " from C#";
            };
            p1.f1 = new Struct1 { a = 55, b = "hello", buffer = new uint[] { 33, 44 } };

            var p2 = m.TestStruct(p1);

            bool[] vb = c.VectorBool(new bool[] { true, false, true, true, false, true });

            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new Form1());
        }
    }
}
