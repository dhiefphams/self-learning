{
    "targets": [
        {
            "target_name": "queue",
            "include_dirs" : [
                "src",
                "<!(node -e \"require('nan')\")"
            ],
            "sources": ["src/withnan.cc"]
        },
        {
                    "target_name": "async",
                    "include_dirs" : [
                        "src",
                        "<!(node -e \"require('nan')\")"
                    ],
                    "sources": ["src/async_nan.cc"]
                }
    ]
}