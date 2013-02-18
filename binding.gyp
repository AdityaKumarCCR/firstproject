{
"targets": [
{
"target_name": "libpng",
"sources": ["src/libpng.cc"],
"libraries": ["<!(lpng15 --libs)", "<!(lz --libs)"],
}
]
}