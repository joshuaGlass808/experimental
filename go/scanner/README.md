# GO Learning / Prototyping
This project was created sometime in early 2018 as a way to learn GO and look at various ways at solving a problem that eventually was rewritten in php7.4+ in a very very unique way (currently closed source at work).

This go is intented to run on a raspberryPi or anything linux based system that is using scan guns via the USB.
This service will use a local sqlite3 for a database, updating it with info like: `"scanner_id, barcode, is_uploaded, scanned_at"`

Most of this was written on something that wasn't using an arm processor, so here is how I cross-compiled it to do so:
`env CC=arm-linux-gnueabi-gcc GOOS=linux GOARCH=arm GOARM=6 CGO_ENABLED=1 go build -o arm_lane_scanner`

DO NOT USE THIS IN ANY PRODUCTION CODE!
