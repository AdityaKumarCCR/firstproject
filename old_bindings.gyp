{
  'variables': {
    "configuration": "Release"
    },
    "target_defaults": {
        "configurations": {
             "Debug": {
             },
             "Release": {
        }    
	}
        },
  'targets': [{
      'target_name': 'hello',
      'sources': [
          'src/libpng.cc'
      ],
      #'link_settings': {
      #    'libraries': [
      #        '--libpng.so'
      #    ]
     # },
      'include_dirs': [ 
          '/usr/include/' 
      ]
   }]
}


