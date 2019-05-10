BEGIN { print "NumberOfHits NumberOfParticlesSim Integral" }
      { print $1/$2*10^7/43*$3}
END   { print "STOP"  }
