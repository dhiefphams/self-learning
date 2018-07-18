using System;

namespace NetStarter.OOP
{
    public abstract class ClassVisibility {
        // internal can be access in other class that locates in same assembly: exe or dll
        internal string Message { get; set;}
    }

    public class WelcomeMessage: ClassVisibility {
        public WelcomeMessage()
        {
            this.Message = "Welcome to .net starter";
        }
    } 
}