using System;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Logging;

// Transient – Created every time they are requested

// Scoped – Created once per scope. Most of the time, scope refers to a web request.
// But this can also be used for any unit of work, such as the execution of an Azure Function.

// Singleton – Created only for the first request.
// If a particular instance is specified at registration time,
// this instance will be provided to all consumers of the registration type.


// ref: https://stackify.com/net-core-dependency-injection/
// 

namespace NetStarter.OOP.DI
 {
    public class IOCContainer
    {
        public static void run()
        {
            var serviceCollection = new ServiceCollection();
            // add logger
            serviceCollection.AddSingleton(new LoggerFactory().AddConsole().AddDebug());
            serviceCollection.AddLogging();

            serviceCollection.AddTransient<RepoConfig, MongoRepo>();
            serviceCollection.AddTransient<DatabaseGeneratorApplication>();

            
            var serviceProvider = serviceCollection.BuildServiceProvider();
            // run the app
            var app = serviceProvider.GetService<DatabaseGeneratorApplication>();
            app.Run();
        }
    } 


    public class DatabaseGeneratorApplication
    {
        private readonly RepoConfig _repoConfig;
        private readonly ILogger<DatabaseGeneratorApplication> _logger;

        public DatabaseGeneratorApplication(
            RepoConfig repoConfig,
            ILogger<DatabaseGeneratorApplication> logger)
        {
            this._repoConfig = repoConfig;
            this._logger = logger;
        }

        public void Run() {
            string dbUrl = this._repoConfig.DBUrl;
            this._logger.LogDebug("Voila " + dbUrl);
            this._logger.LogWarning("Warnnnnn");
        }
    }
    public interface RepoConfig
    {
        string DBUrl { get; }
    }

    public class MongoRepo: RepoConfig
    {
        public string DBUrl { get; }

        public MongoRepo() {
            this.DBUrl = "mongodb://127.0.0.1:27071";
        }
    }
}